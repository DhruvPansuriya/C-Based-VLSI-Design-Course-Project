; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_55 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_62 () (_ BitVec 32))
(assert
 (let ((?x75278 (bvmul arg0_7 arg1_55)))
(let ((?x53659 (bvmul (_ bv4294967295 32) ?x75278)))
(let ((?x63869 (bvmul arg0_7 arg1_62)))
(let ((?x67701 (bvadd ?x63869 ?x53659)))
(and (distinct ?x67701 (_ bv0 32)) true))))))
(check-sat)
