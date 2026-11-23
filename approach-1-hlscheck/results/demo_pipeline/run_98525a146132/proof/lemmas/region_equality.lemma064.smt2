; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x188 (bvmul (_ bv4294967295 32) arg1_7)))
(let ((?x8069 (bvmul (_ bv4294967295 32) arg0_13)))
(let ((?x53 (bvmul arg0_13 arg1_7)))
(let ((?x424 (bvadd ?x53 ?x8069 ?x188)))
(and (distinct ?x424 (_ bv0 32)) true))))))
(check-sat)
