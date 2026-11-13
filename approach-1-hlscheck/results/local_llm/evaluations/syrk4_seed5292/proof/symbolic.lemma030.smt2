; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x774 (bvmul arg0_11 arg0_13)))
(let ((?x4905 (bvmul (_ bv4294967295 32) ?x774)))
(let ((?x4116 (bvmul arg0_11 arg0_7)))
(let ((?x20366 (bvadd ?x4116 ?x4905)))
(and (distinct ?x20366 (_ bv0 32)) true))))))
(check-sat)
