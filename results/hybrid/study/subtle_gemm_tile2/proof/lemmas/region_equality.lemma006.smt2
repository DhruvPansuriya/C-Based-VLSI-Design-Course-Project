; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x73743 (bvmul arg0_1 arg1_6)))
(let ((?x473016 (bvmul (_ bv4294967295 32) ?x73743)))
(let ((?x740813 (bvmul arg0_1 arg1_7)))
(let ((?x503533 (bvadd ?x740813 ?x473016)))
(and (distinct ?x503533 (_ bv0 32)) true))))))
(check-sat)
