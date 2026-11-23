; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_0 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x567103 (bvmul arg0_8 arg1_0)))
(let ((?x483706 (bvmul (_ bv4294967295 32) ?x567103)))
(let ((?x350875 (bvmul arg0_8 arg1_1)))
(let ((?x113480 (bvadd ?x350875 ?x483706)))
(and (distinct ?x113480 (_ bv0 32)) true))))))
(check-sat)
