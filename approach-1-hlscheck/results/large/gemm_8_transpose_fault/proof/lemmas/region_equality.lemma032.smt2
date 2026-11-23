; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_35 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_28 () (_ BitVec 32))
(assert
 (let ((?x73081 (bvmul arg0_3 arg1_35)))
(let ((?x57536 (bvmul (_ bv4294967295 32) ?x73081)))
(let ((?x63631 (bvmul arg0_3 arg1_28)))
(let ((?x58372 (bvadd ?x63631 ?x57536)))
(and (distinct ?x58372 (_ bv0 32)) true))))))
(check-sat)
